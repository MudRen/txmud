// Room: /wiz/louth/c/shuiguodian.c

inherit ROOM;

void create()
{
	set("short", "ˮ����");
	set("long", @LONG
���ǳɶ���һ�Һ���������ˮ���꣬ÿ����ص�ˮ�����Ӷ�
���������������������ز���ˮ��������ÿ�����ˮ���궼����
���ص�����������ۡ��������ȥ��������·��
LONG
	);
	set("exits", ([
  "northeast" : __DIR__"dian2",
  "south" : __DIR__"wmlu5",
]));
        set("objects",([
        __DIR__"npc/xinboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
