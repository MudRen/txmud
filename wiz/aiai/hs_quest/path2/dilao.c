// dilao.c
// by Find.
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
protected int path_long = 5;
protected object setup_npc(object player);

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

object init_dilao(object player) // ����һ���µĵ���
{
        int x,y;
        object room_in,room_out,here, npc, *checks = ({});
                object room_extra;

        while(!create_maze());

        all_rooms = allocate(path_long);
        for(x=0;x<path_long;x++)
                all_rooms[x] = allocate(path_long);

        for(x=0;x<path_long;x++)
                for(y=0;y<path_long;y++)
                        if(all_path[x][y])
                        {
                                object ob;
                                ob = new(__DIR__"dl_room");
                                all_rooms[x][y] = ob;
                                checks += ({ob});
                        }

        room_in = new(__DIR__"enter");
        room_in->set("exits/north",all_rooms[enter->x][enter->y]);
        all_rooms[enter->x][enter->y]->set("exits/south",room_in);
        checks += ({ room_in });
        room_out = new(__DIR__"exit");
        room_out->set("exits/south",all_rooms[leave->x][leave->y]);
        all_rooms[leave->x][leave->y]->set("exits/north",room_out);

                room_extra = new(__DIR__"extra");
        room_out->set("exits/eastdown",room_extra);
        room_extra->set("exits/westup",room_out);
        npc = new(__DIR__"npc/xiuxiu");
        npc->move(room_extra);

        if(objectp(npc = setup_npc(player)))
                npc->move(room_out);

        for(x=0;x<path_long;x++)
                for(y=0;y<path_long;y++)
                        if(objectp(here = all_rooms[x][y]))
                        {
                                int exit = all_path[x][y];
                                object ll;

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

        zhan = new(__DIR__"npc/daozei");

        exp = player->query("combat_exp");
        if(exp > zhan->query("combat_exp"))
                zhan->set("combat_exp",exp);

        return zhan;
}
