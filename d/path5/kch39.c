// Room: /d/path5/kch39.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ɴ����������������ɽ�ˡ�·��һ�Ѱ׻���
������ʲô����ĺ��ǡ����Ϸ���Զ���ǳɶ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"kch40",
  "westup" : __DIR__"kch38",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
