// Room: /d/shaolin/lroad4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������µĹ������ش���Ժ�������һ���ǲ���������
�ģ�С��ʯ�̳ɵ�С���Եĸ񴦵��ľ���С������������̦����
��·ʱ��Ҫ�ر�С�ģ�����һ�������ˤ���ġ����������ǹ�
���������������͵��������ʯ����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"yongdao4",
  "north" : __DIR__"lroad5",
  "west" : __DIR__"puxian",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
