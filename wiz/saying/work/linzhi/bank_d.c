//bank_d.c Ǯׯ�µ��Թ���
inherit VRM_SERVER;
void create()
{
        set_inherit_room(ROOM);
        {if (random(7)>3)
        set_maze_npcs(__DIR__"npc/killer");
        }
        set_maze_long(8);
        set_entry_dir("east");
        set_link_entry_dir("east");
        set_link_entry_room(__DIR__"bank_under");
        set_link_exit_dir("west");
        set_link_exit_room(__DIR__"huang_room");
        set_entry_short("�ص�");
        set_entry_desc(@LONG
������һ��������ʪ�ĵص������Ե�ǽ���Ϲ��ŵ��ˮ�飬
���ϲ����˽�ӡ���ƺ��������˴������߹���
LONG
);
        set_exit_short("�ص�");
        set_exit_desc(@LONG
������һ��������ʪ�ĵص������Ե�ǽ���Ϲ��ŵ��ˮ�飬
���ϲ����˽�ӡ���ƺ��������˴������߹���
LONG
);
        set_maze_room_short("�ص�");
        set_maze_room_desc(@LONG
������һ��������ʪ�ĵص������Ե�ǽ���Ϲ��ŵ��ˮ�飬
���ϲ����˽�ӡ���ƺ��������˴������߹���
LONG
);
        set_outdoors(0);
}
