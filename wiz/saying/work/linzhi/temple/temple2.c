//temple2.c ��ľ�´�
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
�����ǵ�ľ�µĴ��������������ƣ�����ȴ�Ҳ���
ʮ�ֳ��ڵ�ɮ�£��ƺ�����һ��һ�㡣����������˵��ľ�µļ�
���ʦ��һλ�е���ɮ�����ں��޶��ߣ����ﲻ���е�ʧ�䡣��
�����еľ޴���¯�ƺ�Ҳ�м��������ʷ�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "east":__DIR__"t_right2",
        "west":__DIR__"t_left2",
        "north":__DIR__"temple3",
        "south":__DIR__"temple1",
]));
        set("item_desc",([ /* ��ɱ��*/
        "��¯":"һ���޴����¯�������(cha)�˲��ٸ��㡣\n",
]));
        set("objects",([ /* ��������*/
        __DIR__"npc/kid_lama":1,
]));
        setup();
}
