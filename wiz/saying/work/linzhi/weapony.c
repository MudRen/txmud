//weapony.c  ��֥���������
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "�Ծߵ�");
        set("long", @LONG
������֥������Ծߵ꣬��Ϊ�ӽ�ԭʼɭ�֣����ס������
ũ��Ҳ�����ˣ����Ҵ�˵ɭ�������׺ݵ����޳��ˣ����Դ�Ҷ�
����������һЩ��е����Ϊ��Щԭ������Ծߵ������ǳ���
�á��������Ʒ�����ʺ��ڸ����Ļ�����ʹ�ã�����Կ�����һ
�����Լ��á��ſ���һ�����ӣ�Sign����
LONG
        );
        set("exits", ([
        "west":__DIR__"lz_sroad1",
]));
        set("objects", ([
        __DIR__"npc/w_boss" : 1,
]));
        set("item_desc", ([
        "sign": (:look_sign:),
]));
        setup();
}
string look_sign(object me)
{
        return "����д�������ȳ����� ����������
          ����ר����ʽ����������ʱ��ˡ�\n";
}
