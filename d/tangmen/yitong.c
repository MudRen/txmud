// Room: /d/tangmen/yitong.c

inherit ROOM;

void create()
{
	set("short", "һͳ��");
	set("long", @LONG
��������Ƽұ���һͳ�ã�ÿ������¸��ص����ŵ��Ӷ���
�ϻ��Ƽұ�������ʮ�˱������������ټ���ͷĿ���¡��ߴ�ĵ�
�������о��޽��У��Ĵ�����������������һ�Ѿ޴�ĺ�ľ̫ʦ
�Σ�����һ�Ⱦ޴�������ϵ��������ɷ
LONG
	);
	set("exits", ([
  "south" : __DIR__"myuan",
  "north" : __DIR__"xiangfang",
]));

	set("objects", ([
	__DIR__"npc/master_zhen" : 1,
]));

	setup();
	replace_program(ROOM);
}
