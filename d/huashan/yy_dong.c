// Room: /d/huashan/yy_dong.c

inherit ROOM;

void create()
{
	set("short", "ӭ����");
	set("long", @LONG
����һ����Ȼ��ʯ��������͸��һ��ʪ�����´�������ʯ��
ʱ�ص���һ�ε�ˮ�飬�������ָ��������졣���������һЩ
�ɲݣ�����������������Ϣ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"lin1",
]));

	setup();
	replace_program(ROOM);
}
