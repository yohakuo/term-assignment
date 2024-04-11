% 创建一个名为“Plot”的菜单项
hFig = figure('MenuBar', 'default', 'Name', 'Plot');

% 创建一个名为“3D Surface”的子菜单
hMenu = uimenu(hFig, 'Label', 'Plot');
hSubMenu = uimenu(hMenu, 'Label', '3D Surface', 'Callback', @plotSurface);

% 定义3D Surface子菜单的回调函数
function plotSurface(~, ~)
    % 生成曲面数据
    [x, y] = meshgrid(-3:0.1:3);
    z = sin(sqrt(x.^2 + y.^2))./(sqrt(x.^2 + y.^2));
    
    % 绘制曲面
    surf(x, y, z);
    title('3D Surface');
end