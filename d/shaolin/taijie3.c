// Room: /d/shaolin/taijie3.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ������������ʯ�̾͵Ŀ���ʯ�ף�������͡�ɮ����
�����ϣ����ԵĻ���ɮ���ֳ�ľ����ɫׯ�ϣ���λӭ��������֪
��ɮЦ�����档ʯ�׵ľ�ͷ���������¸ߴ��ɽ�š�
LONG
	);

	set("night_long", @LONG
����һ������������ʯ�̾͵Ŀ���ʯ�ף�������ȥ��һ��ɽ
��С·�����Ͽ�ʯ�׵ľ�ͷ���������¸ߴ��ɽ�š�
LONG
	);

	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"taijie2",
  "southwest" : __DIR__"shandao1",
]));

	setup();
	replace_program(ROOM);
}