// /d/hangzhou/minan03.c

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
            "south"  : __DIR__"minan04",
            "north"  : __DIR__"cross",
            "east"   : __DIR__"hotel",
            "west"   : __DIR__"cutshop",
]));
        set("outdoors", "hangzhou");


        set("objects",([
        NPC_DIR"xunpu" : 3,
	NPC_DIR"stdnpc/stdnpc_3" : 2,
]));

        setup();
        replace_program(ROOM);
}

