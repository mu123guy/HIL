function cellInfo = Servo_State_Bus(varargin)
% SERVO_STATE_BUS returns a cell array containing bus object information
%
% Optional Input: 'false' will suppress a call to Simulink.Bus.cellToObject
%                 when the MATLAB file is executed.
% The order of bus element attributes is as follows:
%   ElementName, Dimension, DataType, SampleTime, Complexity, SamplingMode, Min, Max, DocUnits, Description

suppressObject = false;
if nargin == 1 && islogical(varargin{1}) && varargin{1} == false
    suppressObject = true;
elseif nargin > 1
    error('Invalid input argument(s) encountered');
end

cellInfo = { ...
  { ...
    'Servo_State_Bus', ...
    '', ...
    '', ...
    'Auto', ...
    '-1', { ...
        {'Servo_Positions', 1, 'Servo_Positions_Bus', -1, 'real', 'Sample', 'Fixed', [], [], '', ''}; ...
          } ...
  } ...
}';


if ~suppressObject
    % Create bus object in the MATLAB workspace
    Simulink.Bus.cellToObject(cellInfo)
end


% ------- EOF -------