// Room: /d/hangzhou/linmishi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�㷢���Լ�վ��һ���ܲ�͸���ʯ�����棬ǽ���ֺ���Ӳ��
��������������������������������һ�����ŵ�С��������ȴ
�����⿪�ģ��ݽ���һ��ľ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lingarden",
]));

	setup();
	replace_program(ROOM);
}
