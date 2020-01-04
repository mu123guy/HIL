%% PIXHAWK COMMAND
%
% This script works along with the Pix_FCC_flash model. 
% Execute this script before starting the simulation in order to set the
% mode of the pixhawk execution synchronisation


%% Toggle Command Line Output
enable_output = 1;
if(enable_output) disp([newline 'SENDING INITIALIZATION COMMAND TO PIXHAWK' newline]), end

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

%% Specify Command

mode_cmd = uint8(3);
% mode_commands
% 1 -> 
% 2 -> 
% 3 -> 
% 4 -> 

rate_cmd = uint8(1);
% rate_commands
% 1 -> 
% 2 -> 
% 3 -> 
% 4 -> 

com_rate_cmd = uint8(1);
% com_rate_commands
% 1 -> 
% 2 -> 
% 3 -> 
% 4 -> 

default_cmd = uint8(0);
% future purpose

CMD = [mode_cmd rate_cmd com_rate_cmd default_cmd];
CMD = uint8(CMD);

%% Construct Data to send

headerToSend = uint8([8 8]);
whiteNoise = uint8([0 0 0 0 0]);
fill = uint8(zeros(1,82)); %reach necessary message length equal to standard message that pixhawk serial in is expecting

%pack data to byte -> form uint8 vector
message = [whiteNoise headerToSend CMD headerToSend CMD headerToSend CMD headerToSend fill whiteNoise];


%% serial communication
try
    fopen(s);

    %% send data
    
    %Initialize the variable to store the data which is to be received
    data = [];
    
    %Send the command to the pixhawk hardware. 
    fwrite(s,message);
    bytes_sent = s.ValuesSent;
    if(enable_output) disp(['Command sent to Pixhawk.' newline '(' num2str(bytes_sent) ' bytes sent)']), end
    
    %wait for half a sec before reading the data sent by the board.
    if(enable_output) disp(['waiting for response ...']), end
    pause(0.5);
    
    %% receive data
    
    %Read the data sent by the pixhawk board.
    %The data are 4 single precision values(16 bytes). The header
    %associated with this data is [5 5]. Hence expectedDataLength = 18
    expectedDataLength = 19;
    expectedDataLength = 500;
    data = fread(s,expectedDataLength);
       
    %close the connection after reading
    fclose(s);
    delete(s);
    
catch ME
    disp(ME.message)
end

%% unpack received data

if isempty(data)
    if(enable_output) disp([newline 'ERROR: Pixhawk does not respond.']), end
else
    if(enable_output) disp(['Pixhawk respond received.']), end
    
    %Find the packet after stripping the header
    data = data';
    expected_header = [9 9];
    
    %Find the starting indices of 'header' in the 'data' received. It is
    %expected to be 1 in this case
    k = strfind(data,expected_header);
    
    packet = [];
    
    if ~isempty(k) && any(ismember(k,1))
        %get the packet data by stripping the header
        packet = data(length(expected_header)+1:expectedDataLength);
    else
        if(enable_output) disp([newline 'ERROR: Unable to interprete Pixhawk response.']), end
    end
    
    if ~isempty(packet)
        % get data out of packet
        RC_confirm = packet(1);
        CMD_confirm = packet(2);

        %% check validity of confirmation
        if RC_confirm
            if(enable_output) disp(['Command reception confirmed']), end
            if CMD_confirm(1) == CMD(1) && CMD_confirm(2) == CMD(2) && CMD_confirm(3) == CMD(3)
                if(enable_output) disp(['Commands accepted and confiremd by Pixhawk']), end
            else
                if(enable_output) disp([newline 'ERROR: Commands not accepted by Pixhawk']), end
            end
            if(enable_output) disp(['Pixhawk did not receive the command']), end
        end
        
    end

end
data