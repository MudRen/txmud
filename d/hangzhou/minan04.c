// /d/hangzhou/minan04.c

inherit ROOM;

void create()
{
        set("short", "���Ͻ�");
        set("long", @LONG
�񰲽ֹᴩ���ݸ��ϱ���������Ǻ��ݸ�����Ľ����ˣ�
�ĳ�����Ժ֮��ķ��³�����뽨���������ϣ���Ȼ��Ϊ�񰲣�
ʵ����ȴ�ǳ���������ĵط���
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"minan05",
            "north"  : __DIR__"minan03",
            "east"   : __DIR__"jiyuan",
            "west"   : __DIR__"betroom",
]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}

