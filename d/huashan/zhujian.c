// Room: /d/huashan/zhujian.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ǻ�ɽ�ɵ������ء�������������ż��˸ߵĲ�̼��
����һ����¯ð�ż��߸ߵĻ��硣������ɽ�ɵĵ���������æ��
����̼������ͨ��Ľ������ڻ��С�¯�߻���һֻһ�˶�ߵ�
��ˮ�ף�����װ�źں�����Һ�塣������һ��Сľ�ݣ�������ʦ
��ס����
LONG
        );

	set("exits", ([
		"north" : __DIR__"tieku",
		"westup" : __DIR__"luoyanpo",
		"enter" : __DIR__"muwu",
]));

	set("NONPC",1);

        set("outdoors", "huashan");
        set("objects", ([
	__DIR__"npc/zhujianshi":1,
]));
        setup();
        replace_program(ROOM);
}

