// Room: /d/shaolin/caidi.c

inherit ROOM;

void create()
{
	set("short", "�˵�");
	set("long", @LONG
�����������µ�һ��Ƭ�˵أ����ֵ���������˽䣬�ֲ���
��ȥ��ڣ��������������ֲˡ�����Ĳ˽���Ӧȫ�£�ֻ������
��Ƭ�������͵��߲ˣ�����Сɮ��æ����ˮ��԰������������
����Ժ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"w_court",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
