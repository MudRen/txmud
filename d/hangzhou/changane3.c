// /d/hangzhou/changane3.c

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
            "south"  : __DIR__"woodroom",
            "north"  : __DIR__"tangyuanshop",
            "east"   : __DIR__"yuanzi",
            "west"   : __DIR__"changane2",
]));
        set("outdoors", "hangzhou");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_2" : 4,
]));

        setup();
        replace_program(ROOM);
}

