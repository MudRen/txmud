// Room: /d/huashan/husunchou.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��������������������վ��±ڡ�����ǰȥ�����ǻ�ɽ��
���塣���������ƽԭ�������پ�����������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"yuntai",
  "southwest" : __DIR__"ligou",
  "southdown" : __DIR__"tianti2",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
