// /d/hangzhou/minan01.c

inherit ROOM;

void create()
{
        set("short", "�񰲱���");
        set("long", @LONG
�������񰲱����ϣ�ֻ�����������˴�����Ϣ��·�Ķ�����
һ����ꡣ
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"minan02",
            "north"  : __DIR__"ndoor",
            "east"   : __DIR__"bookroom",
]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}

