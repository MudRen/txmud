//bank.c ��֥���Ǯׯ
inherit BANK;
void create()
{
        set("short", "����¡Ǯׯ��֥�ֺ�");
        set("long", @LONG
����¡Ǯׯ�������ĺܴ󣬾�Ȼ��������ԭ�˺��ٵ��ĵط�
���������ǵķֺš�����ϸ�۲���һ�£�������������Ⲣ����
¡������Ϊʲô�����ֵط������굹�����˷ѽ⡣
LONG
);
        set("item_desc", ([
        "sign" :  "����¡ǮׯĿǰ�ṩ�ķ����У�
huan            �һ�Ǯ��
cunqian         ��Ǯ
quqian          ȡǮ
chazhang        ����
zhuan           ת��
",
]));
        set("no_beg", 1);
        set("objects",([
        __DIR__"npc/banker":1,        
]));
        set("exits", ([
        "south": __DIR__"lz_eroad1", 
]));
        setup();
}
