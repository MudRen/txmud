// /d/hangzhou/changanw2.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�������ڳǱ��ĳ������ϣ������򱱲�Զ���Ǻ��ݸ��ı���
���ˣ��������Կ������ٵ��������̴ҴҶ�����������ûʲô
�ر𷱻��ĵط�������һЩ���ֺš�
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"bank",
            "north"  : __DIR__"tearoom.c",
            "east"   : __DIR__"changanw1",
            "west"   : __DIR__"changanw3",
]));
        set("outdoors", "hangzhou");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 2,
]));

        setup();
        replace_program(ROOM);
}

