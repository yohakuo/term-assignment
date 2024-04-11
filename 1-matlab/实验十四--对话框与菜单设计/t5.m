% 创建图形窗口和用户界面组件
fig = figure();

uicontrol('Style', 'text', 'String', 'a:', 'Position', [20 60 20 20]);
ha = uicontrol('Style', 'edit', 'Position', [50 60 100 20]);

uicontrol('Style', 'text', 'String', 'b:', 'Position', [20 40 20 20]);
hb = uicontrol('Style', 'edit', 'Position', [50 40 100 20]);

uicontrol('Style', 'text', 'String', 'n:', 'Position', [20 20 20 20]);
hn = uicontrol('Style', 'edit', 'Position', [50 20 100 20]);

uicontrol('Style', 'pushbutton', 'String', 'Plot', 'Position', [170 20 50 60], 'Callback', ...
    {@plotPolar,ha,hb,hn});

% 回调函数，绘制极坐标曲线
function plotPolar(~, ~,ha,hb,hn)
    % 获取用户输入的参数值
    a = str2double(get(ha, 'String'));
    b = str2double(get(hb, 'String'));
    n = str2double(get(hn, 'String'));

    % 生成极角数组
    theta = linspace(0, 2*pi, 1000);

    % 计算极径数组
    r = a * cos(b + n * theta);

    % 绘制极坐标曲线
    polarplot(theta, r);
end