//xilang1.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�����ȣ��ȶ�����Ž��������ķ羰��ÿ��������ɫ�����Ӽ����
Ҳ�������ߵľ��룬���ɫ�������ߣ��ۻ�ɫ�ĵ�ש�����������棬Ѿ�ߡ�ū
����������ȥ����æ���Լ������飬������һ�㵡�������洫���������˵���
���������߾͵��˺�Ժ�� 
LONG
        );

        set("exits", ([
              "west" : __DIR__"chanting",
              "east" : __DIR__"xilang2",
              "north" : __DIR__"shilu1",
              "south" : __DIR__"shilu2",
        ]));


        set("objects", ([
                __DIR__"npc/yahuan" : 2,
        ]));
 
        setup();
	replace_program(ROOM);
}
