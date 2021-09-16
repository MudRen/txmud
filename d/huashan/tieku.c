// Room: /d/huashan/tieku.c

inherit ROOM;

private void check_weight(object who);

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
������ǻ�ɽ�������������������ˣ�ֻ������ʯ�ѻ���
��Сɽһ�㣬һλ����������ڰ�����������ʯ���ӡ�
LONG
);

        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhujian",
  "north" : __DIR__"sroad1",
]));

        set(SAFE_ENV,1);

        set("objects",([
        __DIR__"npc/shi_daizi" : 1,
]));
        setup();
}

void init()
{
        object me = this_player();

        if( me && (me->query("class") == "huashan") )
                call_out( (: check_weight :),2,me );
}

private void check_weight(object me)
{
        object *inv;
        int i,n,weight = 0;
        string name;

        if(!me || (environment(me) != this_object()))
                return;

        name = me->query("id");

        if(!n=sizeof(inv = filter_array( deep_inventory(me),
                (: $1->is_huashan_tiekuang() && ($1->query_master() == $(name)) :))))
        {
                write("\nʩ���Ӷ���˵����ץ��ʱ��ú�������û�±��Ĵ�Ϲת�Ρ�\n\n");
                return;
        }

        for(i=0; i<n; i++)
        {
                weight += inv[i]->weight();
                        destruct(inv[i]);
        }

        if(!weight)
        {
                write("\nʩ���Ӷ���˵����ץ��ʱ��ú�������û�±��Ĵ�Ϲת�Ρ�\n\n");
                return;
        }

        message_vision("\n$N������������ʯ�ӵ��˿�ʯ�����Ҳ�ۻ��ˡ�\n",me);

        if(me->query("combat_exp") > 50000)
        {
                write("\nʩ���Ӷ���˵����ʦ������������Щ�����ø����ŵĵ������ã�����ĥ�����ʣ�
    ���������ĸ������Ƕ������ɣ���ɽ��ѧҪ���ұ����з����󣡣�\n\n");
                return;
        }

        weight /= 2500;
        me->add("combat_exp",weight);
        me->add("potential",weight/2);

        tell_object(me,sprintf("\n��õ��ˣ�\n %3d �㾭��\n %3d ��Ǳ��\n�����Ծ����֮����������\n\n",
                weight,weight/2));
        me->improve_skill("dodge",weight/2);
}

