// Room: /wiz/louth/a/houlu5.c

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
���Ǻ�ɽ��һ��С·��·�����Զ����Ÿ�������Ļ��ݣ�
ʹ�˸о������ޱȡ�������һ��Сͤ�ӣ���ӳ�ڻ���֮�У�
�Ե�ʮ�ֱ��¡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"houlu6",
  "southwest" : __DIR__"houlu4",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
