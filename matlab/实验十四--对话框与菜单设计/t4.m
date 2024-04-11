% 为当前图形窗口创建快捷菜单
hmenu = uicontextmenu('Parent',gcf);

% 添加设置背景颜色的菜单项
hbg = uimenu(hmenu, 'Label', 'Background Color');
uimenu(hbg, 'Label', 'White', 'Callback', @(~,~) set(gcf, 'Color', 'w'));
uimenu(hbg, 'Label', 'Black', 'Callback', @(~,~) set(gcf, 'Color', 'k'));
uimenu(hbg, 'Label', 'Gray', 'Callback', @(~,~) set(gcf, 'Color', [0.5 0.5 0.5]));

% 添加设置窗口大小的菜单项
hsize = uimenu(hmenu, 'Label', 'Window Size');
uimenu(hsize, 'Label', '640x480', 'Callback', @(~,~) set(gcf, 'Position', [100 100 640 480]));
uimenu(hsize, 'Label', '800x600', 'Callback', @(~,~) set(gcf, 'Position', [100 100 800 600]));
uimenu(hsize, 'Label', '1024x768', 'Callback', @(~,~) set(gcf, 'Position', [100 100 1024 768]));

% 为图形窗口添加快捷菜单
set(gcf, 'UIContextMenu', hmenu);