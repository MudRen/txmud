// Room: /d/shaolin/zhongputang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������µĴ����ã��������������׼ҵ��ӵĵط���ÿ
��������������������ʦ��������ϸ�����������������֤
ʵ����Ʒ��ȷʵû��ʲô���⣬�Ż���Ϊ�����׼ҵ��ӵġ�����
�������ǹ����֣�����ǰԺ�㳡��ࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"f_square_l",
  "west" : __DIR__"gongde3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
