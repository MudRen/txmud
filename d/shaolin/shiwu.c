// Room: /d/shaolin/shiwu.c

inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
�����������µ�һ�������ʯ�ݣ��Ǵ���һЩ�����ɮ�˵�
�ط���ʯ����տյ����ģ�ֻ��һ�����ţ����ŵĲ�Զ����ʯ��
�Ͽ���һ������(couplet)���Ǹ�����ɮ�˺ú÷�ʡ�Լ����⣬
���������ǽ���Ժ��
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "couplet" : "      һέ�ɽ������ŷ��
      ������ڴ���������
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jielv",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
