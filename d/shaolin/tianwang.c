// Room: /d/shaolin/tianwang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������µ������һ�����㿴����������ɫ���
��ʮ���������ķ����Աߵıڻ��ϣ������Ļ�����һЩ���ַ�
��ƮƮ���衣�������Ե���¯�зų����㣬���ƺ�������������
�˼䣬��Ȼ�����������һ�㡣���������������ֵ����䳡��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yanwu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
