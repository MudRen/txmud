// Room: /d/changan/mashi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǳ����ǵ������У�ӭ����һ����ǣ���ʱ���������
������������������������ϡ����ھ��Ƕ��ٹ��ˣ���������
�ļ۸�Ҳ�ܸߣ���ص�����Ҳ����������������������С�һ
�����������������ʱ�ĺ�����������ּۻ��ۡ�
LONG
	);


	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sroad7",
]));
	set("no_clean_up", 0);
	set("objects",([
	__DIR__"npc/ma-fanzi" : 1,
]));
	set("outdoors","changan");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
