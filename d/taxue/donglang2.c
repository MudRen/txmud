// zoulang6.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�����ȣ��ȶ�����Ž��������ķ羰��ÿ��������ɫ�����Ӽ����
Ҳ�������ߵľ��룬���ɫ�������ߣ��ۻ�ɫ�ĵ�ש�����������棬Ѿ�ߡ�ū
����������ȥ����æ���Լ������飬������һ�㵡����
LONG
        );

        set("exits", ([
               "west" : __DIR__"donglang1",
               "east" : __DIR__"shilu5",
               "south" :__DIR__"bingqiku",		  
        ]));

        set("objects", ([
                __DIR__"npc/yahuan1" : 2,
        ]));

        setup();
	replace_program(ROOM);
}
