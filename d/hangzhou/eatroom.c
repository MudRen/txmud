// /d/hangzhou/eatroom.c

inherit ROOM;

void create()
{
        set("short", "С�Ե�");
        set("long", @LONG
���ǳ����ֱߵ�һ��С���ӣ������޷���һЩ�ǹ�������֮
��Ķ�����������˵������ϰ�������Ķ���������ɫ��
LONG
        );
        set("exits", ([ 
            "north"   : __DIR__"changane2",
]));

	set("objects",([
	__DIR__"npc/xiaochi_boss" : 1,
]));

        setup();
        replace_program(ROOM);
}

