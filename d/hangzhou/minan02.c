// /d/hangzhou/minan02.c

inherit ROOM;

void create()
{
        set("short", "�񰲱���");
        set("long", @LONG
���˺�����������һЩС�����ؽֽ�����һ���ϸ�������
������ȥ�����ǵ��ӻ�����ȥ��ʲô������
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"cross",
            "north"  : __DIR__"minan01",
            "east"   : __DIR__"shop",
]));


        set("objects",([
        __DIR__"npc/beggar" : 1,
        NPC_DIR"xunpu" : 1,
]));

        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}

