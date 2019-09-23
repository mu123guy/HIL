%% FLIGHT TABLE HW INTERFACE CONTROL COMPUTER COMMUNICATION TEST
%
% This script works along with the FlightTable_HWInterface_CC model. 
% Execute this script to check the operability of the UDP communication 
% interface and verify the right data transmission by sending test data
% over the ComCheck Channel and comparing it to the looped back feedback 


%% Toggle Command Line Output
enable_output = 1;
if(enable_output) disp([newline 'VERIFY UDP COMMUNICATION WITH FLIGHT TABLE HWI CONTROL COMPUTER' newline]), end


%% Specify Connection Data

%HostIP = '127.0.0.1';
HostPortSend = 25000;
RemoteIP = '127.0.0.1';
RemotePort = 25000;
HostPortReceive = 31000;


%% Set up UDP communication

%sender object
udps = dsp.UDPSender('LocalIPPort',HostPortSend,'RemoteIPAddress',RemoteIP,'RemoteIPPort',RemotePort); %specify!!!
%setup(udps);

%receiver object
udpr = dsp.UDPReceiver('LocalIPPort',HostPortReceive,'RemoteIPAddress',RemoteIP);  %specify!!!
setup(udpr);



%% Specify Test Data

% TBD: think of most significant data
testData1 = double(101);
testData2 = double(-202);
testData3 = double(303);
testData4 = double(404);
testData = [testData1 testData2 testData3 testData4];

%% Construct Data to send

%mimic structure and length of original message
packageFrame= [typecast(boolean(0),'uint8') typecast(boolean(0),'uint8') typecast(double(0),'uint8') typecast(double(0),'uint8') typecast(uint16(0),'uint8') typecast(double(0),'uint8') typecast(double(0),'uint8') typecast(double(0),'uint8')];

packetToSend1 = [uint8(packageFrame) typecast(double(testData1),'uint8')];
packetToSend2 = [uint8(packageFrame) typecast(double(testData2),'uint8')];
packetToSend3 = [uint8(packageFrame) typecast(double(testData3),'uint8')];
packetToSend4 = [uint8(packageFrame) typecast(double(testData4),'uint8')];

packetToSend = [packetToSend1 packetToSend2 packetToSend3 packetToSend4];



%% UDP communication

if(enable_output) disp(['sending test data to IP' RemoteIP ]), end

%loop through test messages
for i=1:4
    
    %send data
    if(enable_output) disp(['[package ' num2str(i) '/4 sent ...']), end
    udps(packetToSend(i));
    
    pause(0.5);
    
    %receive data
    messageReceived = udpr();
    
    if isempty(messageReceived)
        if(enable_output) fprintf('\b'), end
        if(enable_output) disp(' no response]'), end
        if(enable_output) disp(['waiting for response ...']), end
        pause(1);
        %try resend?
        if(enable_output) disp([newline 'ERROR: could not receive answer from FTHWICC [' num2str(4-(i-1)) ' of 4 packages lost]' newline]), end
        release(udps);
        release(udpr);
        return;
    else
        dataReceived(i) = messageReceived;
        if(enable_output) disp(['answer from FTHWICC received [4/4]']), end
    end
    
end

if(enable_output) disp(['answer from FTHWICC received (4/4)']), end

%% close communication

release(udps);
release(udpr);

%% unpack received data

if(enable_output) disp(['unpacking received data ...']), end
for i=1:4

    packet = dataReceived(i);
    loopbackData(i) = typecast(uint8(packet((length(packet)-8):length(packet))),'double'); %extract last 8 bytes (ComCheck signal) and convert to double
        
end

%% Compare feedback data to sent data


missmatch = 0;

for i=1:4
    
    if testData(i) == loopbackData(i)
        %do something?
    else
        missmatch = missmatch + 1;
    end
    
end

if missmatch
    if(enable_output) disp([newline 'ERROR: looped back data does not match the sent one' newline]), end
else
    if(enable_output) disp([ 'all looped back data matches the sent one']), end
    if(enable_output) disp([newline 'COMMUNICATION TEST SUCCESSFUL']), end
    if(enable_output) disp([newline 'UDP INTERFACE TO FTHWICC OPERATIONAL' newline]), end
end


