// Room: /d/shaolin/rroad4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������µĺ�Ժ���������±���һ��ģ����������һ��
С���������������˸�����ľ��С��Ҳ������ɳ�̳ɵģ���Ȼ
ÿ����ʱ��·������Щ��Ţ����Ҳ�������ֵ�һ�󾰹ۡ�������
�����ǹ��������������������Ϸ�����ʯ����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"yongdao4",
  "north" : __DIR__"rroad5",
  "east" : __DIR__"wenshu",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
