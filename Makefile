# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaktion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 15:44:37 by olaktion          #+#    #+#              #
#    Updated: 2019/07/01 01:57:01 by osak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=				doom-nukem

SRC_DIR :=			./src
OBJ_DIR :=			./obj/
INC_DIR :=			./include/

SRC :=              draw_load.c \
					event.c \
					event2.c \
					key_event.c \
					main_cycle.c \
					menu.c\
					move_player.c\
					get_next_line.c\
					done.c\
					init.c\
					cycle.c\
					draw_scr_helper.c\
					draw_scr_nostable.c\
					draw_scr_stable.c\
					load_png.c\
					load_texture.c\
					skybox.c\
					transform_and_render.c\
					view.c \
					parse_player.c\
					parse_sector.c\
					parse_sector2.c\
					parse_vertex.c\
					parse_vertex2.c\
					validate_vertex.c\
					work_with_file.c\
					sprites.c\
					main.c\
					content_loader.c\
                    content_loader_second.c\
                    drawing_sectors.c\
                    event_handler.c\
                    event_listener.c\
                    filling_map.c\
                    filling_map2.c\
                    graphic_tools.c\
                    interface_visualizer.c\
                    lvl_editor.c\
                    map_creator.c\
                    sectors_hendler.c\
                    sectors_hendler2.c\
                    interface_visualizer2.c\
                    interface_visualizer3.c\
                    interface_visualizer4.c\
                    interface_visualizer5.c\
                    pmc.c\
                    start_menu.c\
                    graphic_tools2.c\
                    sprites_2.c\
                    sprites_3.c\
                    drawing_figures.c\
                    init_content.c\
                    event_listener2.c


OBJ =				$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INC :=				defines.h\
					get_next_line.h\
					player_stable.h\
					player_struct.h
					

HEADER :=			$(addprefix $(INC_DIR), $(INC))

LIBFT =				$(LIBFT_DIR)libft.a
LIBFT_DIR :=		$(LIB_DIR)src/libft/
LIBFT_INC :=		$(LIBFT_DIR)inc/
LIBFT_FLAGS :=		-lft -L $(LIBFT_DIR)

SDL_INC :=			-I./frameworks/SDL2.framework/Headers\
                    -I./frameworks/SDL2_ttf.framework/Headers\
                    -I./frameworks/SDL2_image.framework/Headers\
                    -I./frameworks/SDL2_mixer.framework/Headers\


FRM :=              -F./frameworks\
                    -rpath ./frameworks\
                    -framework SDL2 -framework SDL2_ttf -framework SDL2_image -framework SDL2_mixer -framework OpenCL

SDL :=				-F /Library/Frameworks/ -framework SDL2 -F /Library/Frameworks/ -framework SDL2_image -F /Library/Frameworks/ -framework SDL2_ttf -F /Library/Frameworks/ -framework SDL2_mixer
OPENGL :=			-framework OpenGL
APPKIT :=			-framework AppKit
FRAMEWORKS :=		$(SDL) $(OPENGL) $(APPKIT)

CC_FLAGS :=			-Wall -Wextra -Werror 
LINK_FLAGS :=		$(MLX_FLAGS) $(LIBFT_FLAGS)
HEADER_FLAGS :=		-I $(INC_DIR)  -I $(LIBFT_INC) $(SDL_INC)

CC :=				gcc -g

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@gcc $(OBJ) $(LINK_FLAGS) $(FRM) -o $(NAME)
		@echo "Compilation of Doom:	\033[1;32mOK\033[m"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)
		@echo "Removing Doom : \033[1;32mOK\033[m"

$(OBJ_DIR)%.o: %.c $(HEADER)
		@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
		@make -C $(LIBFT_DIR)

clean:
		@rm -f $(OBJ)
		@make clean -C $(LIBFT_DIR)
		@echo "Doom: Removing Objs : \033[1;32mOK\033[m"

fclean: clean
		@rm -f $(NAME)
		@rm -rf $(OBJ_DIR)
		@make fclean -C $(LIBFT_DIR)
		@echo "Removing Doom : \033[1;32mOK\033[m"

re: fclean all

vpath %.c $(SRC_DIR)
