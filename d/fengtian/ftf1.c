// Room: /d/fengtian/ftf1.c

inherit ROOM;

void create()
{
	set("short", "���츮���ſ�");
	set("long", @LONG
�����Ƿ��츮���������ڵأ��ſ������������ֳ��ջ����
ֱ��վ����������������������ŵ�ʯʨ�ӣ����ſڻ���һ��
��ģ��������ԩ������������������ԩ�� 
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xm2",
]));
        set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
