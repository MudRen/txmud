// /d/hangzhou/cross.c

inherit ROOM;

void create()
{
        set("short", "ʮ��·��");
        set("long", @LONG
�������񰲽ֺͳ����ֽ���ĵط���Ҳ�������ֵĵط�����
ʱ�йٱ������ﾭ��������������ΰ����ǲ��������¿�ȥ��
������ĥ�Ÿ������ĸ�����
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"minan03",
            "north"  : __DIR__"minan02",
            "east"   : __DIR__"changane1",
            "west"   : __DIR__"changanw1",
]));

	set("objects",([
	__DIR__"npc/wushi" : 2,
]));

        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}

