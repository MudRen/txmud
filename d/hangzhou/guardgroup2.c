// Room: /d/hangzhou/guardgroup2.c

inherit ROOM;

void create()
{
	set("short", "�ھִ���");
	set("long", @LONG
�ھִ�������ǽ�Ϲ���һ���轣ͼ��ͼ�е���ʿӢ��������
��˵��������Զ�ھֵĿ�ɽ��������Զ���轣ͼ�������һ�ź�
ľ���������Ա߰�������̫ʦ�Σ��������ھ��ճ����µĵط���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guardgroup1",
]));

	setup();
	replace_program(ROOM);
}
