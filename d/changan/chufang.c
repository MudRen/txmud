// Room: /d/changan/chufang.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����������¥�ĺ���������������������һ����̨����
�������޴��ˮ�ױ�����һ���ľ��������ļ����϶������ù�
��������ӡ��ſڹ���һ��ľ����(pai)��
LONG
	);
        set(SAFE_ENV,1);
	set("exits",([
	"west" : __DIR__"jiulou",
]));
	set("item_desc",([
                "pai" : "����ϴ(xi)���ӡ�ϴ���С����\n",
]));

	set("objects",([
		__DIR__"npc/cooker" : 1,
]));
	setup();
	replace_program(ROOM);
}
