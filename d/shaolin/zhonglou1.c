// Room: /d/shaolin/zhonglou1.c

inherit ROOM;

void create()
{
	set("short", "��¥һ��");
	set("long", @LONG
�����������µ���¥һ�㣬ÿ�첻���������Σ���������
��������Ҫ�������ó�����������������ÿ���̵Ĵ�䣬����
������ᣬ�������������ӣ����������������������������
���ǽ����޵˳¥����������¥��¥��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"zhonglou2",
  "west" : __DIR__"jinnaluo",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
