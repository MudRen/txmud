// midao.c
// original version written by Find.
// modified by aiai

#define N               8
#define S               4
#define W               2
#define E               1
#define ALL             15

class coordinate{ int x; int y; }
class coordinate *newpath = ({}),
        enter,
        leave;

protected mixed *all_path, *all_rooms;
protected int path_long = 4;    // �ȵ���СһЩ
protected object setup_npc(object player);

protected int endure_times=5;   // 20����֮�ڵİ�ȫ����

protected int random_out(int x,int y,int n)
{
        int *outs = ({}), retn = 0;

        if( n&W
        && ((x-1) >= 0)
        && !all_path[x-1][y] )
                outs += ({ W });

        if( n&E
        && ((x+1) < path_long)
        && !all_path[x+1][y] )
                outs += ({ E });

        if( n&S
        && ((y-1) >= 0)
        && !all_path[x][y-1] )
                outs += ({ S });

        if( n&N
        && ((y+1) < path_long)
        && !all_path[x][y+1] )
                outs += ({ N });

        if(sizeof(outs) >= 3)
                outs -= ({ outs[random(sizeof(outs))] });

        for(int i=0;i<sizeof(outs);i++)
                retn |= outs[i];

        return retn;
}

protected void link_to_west(int x,int y)
{
        class coordinate temp;
        if( (x-1) < 0 )
                return;

        temp = new(class coordinate);
        temp->x = x-1;
        temp->y = y;

        if(all_path[temp->x][temp->y])
                return;

        all_path[x][y] |= W;
        all_path[temp->x][temp->y] |= E;
        newpath += ({temp});
}

protected void link_to_east(int x,int y)
{
        class coordinate temp;
        if( (x+1) >= path_long )
                return;

        temp = new(class coordinate);
        temp->x = x+1;
        temp->y = y;

        if(all_path[temp->x][temp->y])
                return;

        all_path[x][y] |= E;
        all_path[temp->x][temp->y] |= W;
        newpath += ({temp});
}

protected void link_to_south(int x,int y)
{
        class coordinate temp;
        if( (y-1) <0 )
                return;

        temp = new(class coordinate);
        temp->x = x;
        temp->y = y-1;

        if(all_path[temp->x][temp->y])
                return;

        all_path[x][y] |= S;
        all_path[temp->x][temp->y] |= N;
        newpath += ({temp});
}

protected void link_to_north(int x,int y)
{
        class coordinate temp;
        if( (y+1) >= path_long)
                return;

        temp = new(class coordinate);
        temp->x = x;
        temp->y = y+1;

        if(all_path[temp->x][temp->y])
                return;

        all_path[x][y] |= N;
        all_path[temp->x][temp->y] |= S;
        newpath += ({temp});
}

protected int create_maze()
{
        int i;
        class coordinate *valid_leaves=({}),temp;

        all_path = allocate(path_long);
        for(i=0;i<path_long;i++)
                all_path[i] = allocate(path_long);

        enter = new(class coordinate);

        enter->x = 2;
        enter->y = 0;

        newpath += ({ enter });

        do
        {
                int x,y,out,numb;

                if( !(numb=sizeof(newpath)) )
                        continue;
                numb = random(numb);
                reset_eval_cost();
                x = newpath[numb]->x;
                y = newpath[numb]->y;

                out = ALL^(all_path[x][y]);
                out = random_out(x,y,out);

                if(!out)
                {
                        newpath -= ({ newpath[numb] });
                        continue;
                }

                if(out&W) link_to_west(x,y);
                if(out&E) link_to_east(x,y);
                if(out&N) link_to_north(x,y);
                if(out&S) link_to_south(x,y);

                newpath -= ({ newpath[numb] });
        }
        while (sizeof(newpath));

        for(i=0;i<path_long;i++)
                if(all_path[i][path_long-1])
                {
                        temp = new(class coordinate);
                        temp->x = i;
                        temp->y = path_long-1;
                        valid_leaves += ({temp});
                }

        if( !(i=sizeof(valid_leaves)) )
                return 0;

        if(i == 1)
                leave = valid_leaves[0];
        else
                leave = valid_leaves[random(i)];

        return 1;
}

object init_dilao(object player) // ����һ���µ��ص�
{
        int x,y;
        int i;
        object room_in,room_out,here, npc, ll, *checks = ({});

        while(!create_maze());

        all_rooms = allocate(path_long);
        for(x=0;x<path_long;x++)
                all_rooms[x] = allocate(path_long);

        for(x=0;x<path_long;x++)
                for(y=0;y<path_long;y++)
                        if(all_path[x][y])
                        {
                                object ob;
                                ob = new(__DIR__"md_room");
                                all_rooms[x][y] = ob;
                                checks += ({ob});
                        }

        room_in = new(__DIR__"md_enter");
        room_in->set("exits/north",all_rooms[enter->x][enter->y]);
        all_rooms[enter->x][enter->y]->set("exits/south",room_in);
        checks += ({ room_in });
        room_out = new(__DIR__"md_exit");
        room_out->set("exits/south",all_rooms[leave->x][leave->y]);
        all_rooms[leave->x][leave->y]->set("exits/north",room_out);

        npc = new(__DIR__"npc/xiuxiu");
        npc->move(room_out);

        if( objectp(npc = setup_npc(player)) )
        {

                npc->move(room_out);
                if ( npc->query("high_level") )
                        for (i=0; i<random(5)+1; i++)
                                {
                                        ll=new(__DIR__"npc/loulou");
                                        ll->set("combat_exp", 2000000);
                                        ll->set("max_kee", 500);
                                        ll->set("eff_kee", 500);
                                        ll->set("kee", 500);
                                        ll->set("max_force", 1500);
                                        ll->set("eff_force", 1500);
                                        ll->set("force", 1500);
                                        ll->set("force_factor", 50);
                                        ll->set_skill("dodge",150);
                                        ll->set_skill("parry",150);
                                        ll->set_skill("unarmed",150);
                                        ll->set_skill("ganchan",150);
                                        ll->set_skill("lianhuan-blade",150);
                                        ll->set_skill("feilong-quan",150);
                                        ll->map_skill("blade", "lianhuan-blade");
                                        ll->map_skill("parry", "lianhuan-blade");
                                        ll->map_skill("dodge", "ganchan");
                                        ll->map_skill("unarmed", "feilong-quan");
                                        ll->move(room_out);
                                }
        }

        for(x=0;x<path_long;x++)
                for(y=0;y<path_long;y++)
                        if(objectp(here = all_rooms[x][y]))
                        {
                                int exit = all_path[x][y];

                                if(exit&E)
                                        here->set("exits/east",all_rooms[x+1][y]);
                                if(exit&S)
                                        here->set("exits/south",all_rooms[x][y-1]);
                                if(exit&W)
                                        here->set("exits/west",all_rooms[x-1][y]);
                                if(exit&N)
                                        here->set("exits/north",all_rooms[x][y+1]);
                                if(!random(4))
                                {
                                        ll = new(__DIR__"npc/loulou");
                                        ll->move(here);
                                }
                        }

        room_out->set_check_array(checks);
        all_path = 0;
        all_rooms = 0;
        return room_in;
}

protected object setup_npc(object player)
{
        object zhan;
        int exp;


        if(!objectp(player))
                return 0;

        zhan = new(__DIR__"npc/zhan");

        exp = player->query("combat_exp");
        if(exp > zhan->query("combat_exp"))
                zhan->set("combat_exp",exp);

        if ( (player->query("zfx_in_20min") &&
                player->query("zfx_in_20min", 1) > endure_times) ||
                random(10)>6 )
        {
                zhan->set("high_level", 1);

                zhan->set("combat_exp",exp+random(exp));
                zhan->set_skill("ganchan",200+random(100));
                zhan->set_skill("lianhuan-blade",200+random(100));
                zhan->set_skill("feilong-quan",200+random(100));
                zhan->map_skill("blade", "lianhuan-blade");
                zhan->map_skill("parry", "lianhuan-blade");
                zhan->map_skill("dodge", "ganchan");
                zhan->map_skill("unarmed", "feilong-quan");

                exp=1000+random(1000);
                zhan->set("max_kee", exp*2);
                zhan->set("eff_kee", exp*2);
                zhan->set("kee", exp*2);
                zhan->set("max_sen", exp);
                zhan->set("eff_sen", exp);
                zhan->set("sen", exp);
                zhan->set("max_gin", exp);
                zhan->set("eff_gin", exp);
                zhan->set("gin", exp);
                zhan->set("max_force", 3000);
                zhan->set("eff_force", 3000);
                zhan->set("force", 3000);
                zhan->set("force_factor", 100+random(100));
        }

        return zhan;
}


