// /d/hangzhou/guotaiw2.c

inherit ROOM;

void create()
{
        set("short", "��̩·");
        set("long", @LONG
�����Ǻ����������һ���֣����ݸ���֪�����ž���������
�����ϣ��������·�ϵ�����Ҳ�Ƚ��٣����⣬������ϱ���
��Զ�ھ�Ҳ�������������ϡ�
LONG
        );
        set("exits", ([ 
            "north"  : __DIR__"zhifu",
            "east"   : __DIR__"guotaiw1",
            "west"   : __DIR__"guotaiw3",
]));
        set("outdoors", "hangzhou");
        set("cannot_build_home", 1);

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 2,
]));

        setup();
        replace_program(ROOM);
}

