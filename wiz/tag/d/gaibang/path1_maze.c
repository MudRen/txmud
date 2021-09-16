// path1_maze.c

inherit VRM_SERVER;

void create()
{
        set_inherit_room(ROOM);
        set_maze_long(40);
        set_maze_npcs(__DIR__"npc/maze_snake");
        set_entry_dir("south");
        set_link_entry_dir("southeast");
        set_link_entry_room("/wiz/tag/d/path1/tch_ft17");
        set_link_exit_dir("north");
        set_link_exit_room(__DIR__"path1_maze_hut");
        set_entry_short("����");
        set_entry_desc(@LONG
����ǰ��һƬï�ܵ����֣����߼ʶ�����������˵�Ǿ�����
���ˣ����浽�������ߣ�����ԥ��Ҫ��Ҫ��ȥ������
LONG
);
        set_exit_short("����");
        set_exit_desc(@LONG
�����������ֵı�Ե����������Ѿ���ϡ���ˣ�����Ҳ����
�������ˡ�
LONG
);
        set_maze_room_short("����");
        set_maze_room_desc(@LONG
������������֮�У�����Χ������ɫʲô������������Ȼ��
��Ҳ���̵ģ�����ѷ��嵽������Χ�ǲ������ߣ�ֻ�мӱ�С��
����ˡ�
LONG
);
        set_outdoors(1);
}
