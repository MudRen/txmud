//t_right1.c ��ľ���ڵ����֡�
inherit VRM_SERVER;
void create()
{
        set_inherit_room(ROOM);
        set_maze_long(10);
        set_entry_dir("west");
        set_link_entry_dir("west");
        set_link_entry_room(__DIR__"temple1");
        set_link_exit_dir("east");
        set_link_exit_room(__DIR__"fire_hole");
        set_entry_short("����");
        set_entry_desc(@LONG
�����ǵ�ľ�µ����֣����������ȫ����ǰ��ɮ�˵��Ź�
���֮�����ƺ��е�����ɭɭ�ء�
LONG
);
        set_exit_short("����");
        set_exit_desc(@LONG
�����ǵ�ľ�µ����֣����������ȫ����ǰ��ɮ�˵��Ź�
���֮�����ƺ��е�����ɭɭ�ء�
LONG
);
        set_maze_room_short("����");
        set_maze_room_desc(@LONG
�����ǵ�ľ�µ����֣����������ȫ����ǰ��ɮ�˵��Ź�
���֮�����ƺ��е�����ɭɭ�ء�
LONG
);
        set_outdoors(1);
}
