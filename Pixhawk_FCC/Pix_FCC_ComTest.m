%% PIXHAWK COMMUNICATION TEST
%
% This script works along with the Pix_FCC_flash model. 
% Execute this script to check the operability of the serial communication 
% interface and verify the right data transmission by sending test data
% over the TestData Channel and comparing it to the looped back feedback 


%% Toggle Command Line Output
enable_output = 1;
if(enable_output) disp([newline 'VERIFY SERIAL COMMUNICATION WITH PIXHAWK FCC' newline]), end

%% Set up serial communication
% change the comport value below to the one on which the Pixhawk board is
% connected on your Host machine
comport = 'COM3';
delete(instrfind('Port',comport));

%open serial object
s = serial(comport);
%The Baudrate of 115200 is set on the Pixhawk board as well in the
%px4demo_serial model
s.BaudRate = 115200;

%% Specify Test Data

% TBD: think of most significant data
testData1 = single(101);
testData2 = single(-202);
testData3 = single(303);
testData4 = single(404);
testData = [testData1 testData2 testData3 testData4];

%% Construct Data to send

%mimic structure and length of original message
packageFrame= [typecast(uint16(1),'uint8') uint8(1) uint8(1) uint8(zeros(1,40))];

headerToSend = uint8([7 7]);
whiteNoise = uint8([0 0 0 0 0]);

packetToSend1 = [uint8(packageFrame) typecast(single(testData1),'uint8')];
packetToSend2 = [uint8(packageFrame) typecast(single(testData2),'uint8')];
packetToSend3 = [uint8(packageFrame) typecast(single(testData3),'uint8')];
packetToSend4 = [uint8(packageFrame) typecast(single(testData4),'uint8')];

%pack data to byte -> form uint8 vector
MessageToSend1 = [whiteNoise headerToSend packetToSend1 headerToSend packetToSend1 headerToSend whiteNoise];
MessageToSend2 = [whiteNoise headerToSend packetToSend2 headerToSend packetToSend2 headerToSend whiteNoise];
MessageToSend3 = [whiteNoise headerToSend packetToSend3 headerToSend packetToSend3 headerToSend whiteNoise];
MessageToSend4 = [whiteNoise headerToSend packetToSend4 headerToSend packetToSend4 headerToSend whiteNoise];
message = [MessageToSend1 MessageToSend2 MessageToSend3 MessageToSend4];

%% serial communication
try
    fopen(s);
    
    if(enable_output) disp(['send test messages to pixhawk ...']), end
    
    %loop through test messages
    for i=1:4
    
        %Initialize/clear the variable to store the data which is to be received
        data = [];
        
        %% send data
        
        %Send test message to the pixhawk hardware. 
        fwrite(s,message(i));
        bytes_sent = s.ValuesSent;
        if(enable_output) disp(['[message 1 sent (' num2str(bytes_sent) ' bytes) ... ']), end
        
        %wait for half a sec before reading the data sent by the board.
        pause(0.5);
        
        %% receive data
        
        %Read the data sent by the pixhawk board.
        expectedDataLength = 62; %length of standard message from pixhawk
        data = fread(s,expectedDataLength);
        
        if ~isempty(data)
            if(enable_output) fprintf('\b'), end
            if(enable_output) disp(['response received]']), end
            %save data in variable
            fb(i) = data;
        else
            if(enable_output) fprintf('\b'), end
            if(enable_output) disp(['no response]']), end
            fb(i) = [];
        end
            
        
    end
        
    %close the connection after reading
    fclose(s);
    delete(s);
    
catch ME
    disp(ME.message)
end

%% unpack received data

for i=1:4

    if isempty(fb(i))
        
        testDataRC(i) = single(-1); %error value
        
    else
    
        %Find the packet after stripping the header
        fb(i) = fb(i)';
        expected_message_length = 48; 
        expected_header = [5 5];      
        expected_header_length = length(expected_header);
        expected_packet_length = expected_message_length + expected_header_length;
        
        packet = uint8(zeros(1,expected_message_length));
        packetfound = false;
        
        % locate packet in data
        
        data_tmp = feedback(i);
        
        % First, find possible header start locations; i.e., match the first element in the
        % header.
        start = find(data_tmp==expected_header(1));
    
        % Next remove start values that are too close to the end to possibly match
        % the header.
        endVals = start+expected_header_length-1;
        start(endVals>length(data_tmp)) = [];
    
        % Next, loop over elements of header, usually much shorter than length of
        % array, to check which possible header start locations are valid still.
        for pattval = 2:expected_header_length
            % check viable locations in array
            locs = expected_header(pattval) == data_tmp(start+pattval-1);
            % delete false ones from indices
            start(~locs) = [];
        end
    
        %Packet = Data - Header
        if ~isempty(start)
            for j = 1:(length(start)-1)
                %Verify if the size of data between 2 consecutive header start
                %indices is equal to the expectedPacketSize
                if isequal(start(j+1)-start(j),expected_packet_length)
            
                    %Extract the packet by stripping the header from the data
                    packet = data_tmp(start(j)+expected_header_length:start(j+1)-1);
                    if ~isequal(length(packet),(expected_packet_length-expected_header_length))
                        error(['ERROR:Wrong packet size']);
                    end
            
                    %Once a valid packet is found, exit the for loop
                    packetfound = true;
                    break;
                else
                    continue
                end
            end
        else
            packetfound = false;
        end
        
        messageRC = uint8(packet);
        testDataRC(i) = typecast(uint8(messageRC(45:48)),'single');
        
    end

end

%% Compare feedback data to sent data

% TBD!!: check status bits??!

missmatch = 0;

for i=1:4
    
    if testData(i) == testDataRC(i)
        %do something?
    else
        missmatch = missmatch + 1;
    end
    
end

if missmatch
    if(enable_output) disp([newline 'ERROR: looped back data does not match the sent one' newline]), end
else
    if(enable_output) disp(['all looped back data matches the sent one']), end
    if(enable_output) disp([newline 'COMMUNICATION TEST SUCCESSFUL']), end
    if(enable_output) disp([newline 'SERIAL INTERFACE OPERATIONAL' newline]), end
end


