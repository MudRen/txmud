// Room: chengxf10.c

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�����ǳ���ة�ฮ�����ң��ӼҾ�Ͱ�������������Ӧ����
ة��ͷ��˵����ҡ�Ѭ¯��Ѭ�Ų�֪����ʲô�㣬�ƽ�Ĵ�����
����������Ķ��ţ�����ǽ���Ϲ���һ�š���ظͼ������������
���Ǻ�����
LONG
	);

        set("exits", ([
  "west" : __DIR__"chengxf9",
]));
        set("item_desc", ([ /* sizeof() == 2 */
                "��ظͼ": "�����ظͼ����������������Ī���Ǵ�ʦ����ӵ��漣��\n",
        ]));

	set("objects",([
	__DIR__"npc/furen" : 1,
]));

        setup();
	replace_program(ROOM);
}