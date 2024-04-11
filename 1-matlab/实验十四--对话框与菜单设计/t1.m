function myDialog()
    % 创建对话框
    dialogBox = figure('Name', 'My Dialog Box', 'NumberTitle', 'off', 'MenuBar', 'none', 'ToolBar', 'none', 'Position', [300, 300, 200, 120], 'Resize', 'off');

    % 创建编辑框
    editBox = uicontrol('Style', 'edit', 'String', '0', 'Position', [50, 60, 100, 30], 'FontSize', 12);

    % 创建按钮
    addButton = uicontrol('Style', 'pushbutton', 'String', 'Add 5', 'Position', [50, 20, 100, 30], 'FontSize', 12, 'Callback', @addCallback);

    % 回调函数，用于处理按钮点击事件
    function addCallback(hObject, eventdata)
        % 获取编辑框中的数字
        num = str2double(get(editBox, 'String'));

        % 将数字加5
        num = num + 5;

        % 将结果显示在编辑框中
        set(editBox, 'String', num2str(num));
    end
end
