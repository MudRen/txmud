// /d/hangzhou/minan05.c

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
            "south"  : __DIR__"cross1",
            "north"  : __DIR__"minan04",
            "east"   : __DIR__"dangpu",
            "west"   : __DIR__"zhubaoshop",
]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}

