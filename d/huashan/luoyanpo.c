// Room: /d/huashan/luoyanpo.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һ����̫��Ķ��£������������ܣ��ϷɵĴ��㳣��
��������ͣ���������ǻ�ɽ�ɵ������ء���˵��ϼ�����ؽ�����
һ�����ߵߵ���������������������˵���Ľ����Ǻܺ�����
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  "westdown" : __DIR__"xiaolu9",
  "eastdown" : __DIR__"zhujian",
]));

	set("outdoors", "huashan");
	set("objects", ([
	__DIR__"npc/yetu":2,
]));

        setup();
        replace_program(ROOM);
}

