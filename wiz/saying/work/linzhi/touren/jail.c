//jail.c ��֥��ͷ�˸��ļ����ص���
inherit VRM_SERVER;
void create()
{
        set_inherit_room( LIGHT_ROOM );
        set_maze_long(10);
        set_entry_dir("west");
        set_link_entry_dir("up");
        set_link_entry_room(__DIR__"secrety");
        set_link_exit_dir("east");
        set_link_exit_room(__DIR__"real_jail");
        set_entry_short("�η�");
        set_entry_desc(@LONG
������һ��СС���η���ǽ���Ϲ��ŵ��ˮ�飬�ǳ��ĳ�
ʪ�������ֱ������ס�ĵط��������˭��������������ǵ�
ù֮���ˡ�
LONG
);
        set_exit_short("�ص�");
        set_exit_desc(@LONG
������һ��СС���η���ǽ���Ϲ��ŵ��ˮ�飬�ǳ��ĳ�
ʪ�������ֱ������ס�ĵط��������˭��������������ǵ�
ù֮���ˡ�
LONG
);
        set_maze_room_short("�ص�");
        set_maze_room_desc(@LONG
������һ��СС���η���ǽ���Ϲ��ŵ��ˮ�飬�ǳ��ĳ�
ʪ�������ֱ������ס�ĵط��������˭��������������ǵ�
ù֮���ˡ�
LONG
);
        set_outdoors(0);
}
