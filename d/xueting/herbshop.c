// Room: /d/snow/herbshop.c
inherit ROOM;
void create()
{
        set("short", "ɣ��ҩ��");
        set("long", @LONG
������һ���ģ��С��ҩ�̡���ֵ��������������Ų���һ˿
ҩ��Ӧ�е�ҩζ���е�ֻ��һ�ɵ�����̴�㣬���˾����Ŀ�������
ҩ�̵Ĺ�̨���ڵ��������һ�棬��̨����һ���޴��ҩ��(cabinet)��
�����С����ֻ�����ߡ��˰ٸ�֮�࣬����ȫ��û������ǩ��ҩ��
�ĳ����ڶ��ߡ�
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "cabinet" : "һ���޴��ɼľҩ�񣬴�������ɫ������������ĥ�÷����ĺۼ���
���ҩ���������൱��Զ�ˣ���һ���������ǣ�ҩ���ǽ���ƺ���
�÷ǳ����ܣ�������˿����϶��
",
]));
        set(SAFE_ENV, 1);
        set("exits", ([ /* sizeof() == 1 */
                "north" :__DIR__"epath",
        ]));
        set("objects", ([
//                __DIR__"npc/herbalist": 1,
                __DIR__"npc/doctor": 1,
        ]) );
        setup();
        replace_program(ROOM);
}