// Room: /wiz/louth/a/houlu1.c

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
���Ǻ�ɽ��һ��С·��·�����Զ����Ÿ�������Ļ��ݣ�
ʹ�˸о������ޱȡ�����������С·�ϣ���һ���Ŀ�������
�о���������һ����������Χ�ľ��½�Ȼ��ͬ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houlu2",
  "south" : __DIR__"shanlu7",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
