// Room: /d/hangzhou/zhubaoshop.c

inherit ROOM;

void create()
{
	set("short", "�鱦��");
	set("long", @LONG
����һ���ģ������鱦�꣬���⿴��ȥȴ��������ģ���
˵������ϰ����Щ�취��������Щ�رߺ͹���ĺö���������
����֪���������˵�������Щ�鱦�������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"minan05",
]));

	setup();
	replace_program(ROOM);
}
