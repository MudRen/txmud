// Room: /d/changan/gaibang.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�����������Ժ���᷿����ʱȴ��ؤ��ĳ����ֶ档ؤ��һ
���ǽ����ϵ�һ����ɣ���ͽ�鼰�ĺ�������˭Ҳ�벻��������
�ֶ棬����������ƾɵĴ�լ�ڣ���Զ�����м���ؤ����ӣ���
�����ɹ��̫������ʱ�����۽�Ʋ���㡣������������Ժ����
Ժ�ˡ�
LONG
	);
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"badroom",
]));

	setup();
	replace_program(ROOM);
}
