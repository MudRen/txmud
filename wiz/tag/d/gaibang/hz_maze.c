// hz_maze.c ���ݱ��ߵ������Թ�

inherit VRM_SERVER;

void create()
{
        set_inherit_room(ROOM);
        set_maze_long(15);
        set_entry_dir("east");
        set_link_entry_dir("east");
        set_link_entry_room(__DIR__"room");
        set_link_exit_dir("west");
        set_link_exit_room(__DIR__"room");
        set_entry_short("����");
        set_entry_desc(@LONG
��������һƬïʢ�������С������Ǹ�һ��Ƭ���̵����֣�
���˵�Ǽ����Ⱥ��ݳǶ���С�������������£������������ҵ�
��������Ҫ����������͵����ְ���
LONG
);
        set_exit_short("����");
        set_exit_desc(@LONG
�������߳����Ǽ�������֡�Ҫ���������ã�����ܾ���ʧ����
Ƭ�������ˡ�����һ���������ƺ�����������һ����ݡ�
LONG
);
        set_maze_room_short("����");
        set_maze_room_desc(@LONG
�㴩����һƬ��ï������֮�С�������ֻ����ɫ��������
̧��ͷ���춼�������������ķ�����������Ա��巽��
LONG
);
        set_outdoors(1);
}
